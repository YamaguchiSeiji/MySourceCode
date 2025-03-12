using UnityEngine;

public class ObjectSpawner : MonoBehaviour
{
    public GameObject[] objectPrefabs; // 生成するオブジェクトのプレハブのリスト
    public Transform spawnPoint; // 生成する位置
    public Transform targetPoint; // 消える位置
    public float initialSpawnInterval = 2.0f; // 初期生成間隔（秒）
    public float initialSpeed = 2.0f; // 初期移動速度
    public float minSpawnInterval = 0.3f; // 最小生成間隔（秒）
    public float maxSpeed = 10.0f; // 最大速度
    public float speedIncrement = 0.1f; // 速度増加量
    public float spawnIntervalDecrement = 0.1f; // 生成間隔減少量
    public float speedDecreaseOnMiss = 0.3f; // ミス時の速度減少量
    public float spawnIntervalDecrementOnMiss = 0.2f; // ミス時の生成間隔減少量

    private float spawnInterval; // 現在の生成間隔
    private float speed; // 現在の移動速度
    private float timer;

    private float initialMovementSpeed; // 初期移動速度を保持するための変数

    // Singleton instance
    public static ObjectSpawner Instance { get; private set; }

    void Awake()
    {
        Instance = this;
    }

    void Start()
    {
        spawnInterval = initialSpawnInterval;
        speed = initialSpeed;
        initialMovementSpeed = initialSpeed; // 初期移動速度を保存
        timer = spawnInterval; // タイマーを初期生成間隔に設定
    }

    void Update()
    {
        timer -= Time.deltaTime; // タイマーを減少させる

        if (timer <= 0f)
        {
            SpawnObject(); // タイマーが0以下になったらオブジェクトを生成
            timer = spawnInterval; // タイマーをリセット
        }

        // スコアに応じて生成間隔を調整する
        if (ScoreManager.Instance != null)
        {
            int score = ScoreManager.Instance.score;
            float scoreFactor = Mathf.Max(0, score / 100f);

            float newSpawnInterval = initialSpawnInterval - scoreFactor * spawnIntervalDecrement;
            spawnInterval = Mathf.Max(minSpawnInterval, newSpawnInterval); // スコアに応じて生成間隔を調整
        }
    }

    void SpawnObject()
    {
        if (objectPrefabs != null && objectPrefabs.Length > 0 && spawnPoint != null)
        {
            int randomIndex = Random.Range(0, objectPrefabs.Length);
            GameObject spawnedObject = Instantiate(objectPrefabs[randomIndex], spawnPoint.position, Quaternion.identity);

            // Draggableがなければ追加
            if (spawnedObject.GetComponent<Draggable>() == null)
            {
                spawnedObject.AddComponent<Draggable>();
            }

            // ConveyorMoverがなければ追加して初期化
            ConveyorMover mover = spawnedObject.GetComponent<ConveyorMover>();
            if (mover == null)
            {
                mover = spawnedObject.AddComponent<ConveyorMover>();
            }
            mover.Initialize(targetPoint, speed);
        }
        else
        {
            Debug.LogError("ObjectPrefabs が設定されていないか、空です。または SpawnPoint が設定されていません");
        }
    }

    // スコアに応じて速度を増加させる関数
    public void IncreaseSpeedWithScore()
    {
        speed = Mathf.Min(maxSpeed, speed + speedIncrement); // 一定量の速度を加算し、最大速度を超えないようにする
    }

    // ミス時に呼ばれる関数
    public void OnMiss()
    {
        // 生成間隔を増やす
        spawnInterval += spawnIntervalDecrementOnMiss;

        // 初期生成間隔を超えないように調整
        spawnInterval = Mathf.Min(initialSpawnInterval, spawnInterval);

        // 移動速度を減少させる
        speed -= speedDecreaseOnMiss;

        // 初期移動速度以下にならないように調整
        speed = Mathf.Max(initialMovementSpeed, speed);
    }

    public void ResetSpawnIntervalAndSpeed()
    {
        // 生成間隔と速度を初期設定値にリセットする処理
        spawnInterval = initialSpawnInterval;
        speed = initialSpeed;
    }
}
