using UnityEngine;
using TMPro; // TextMeshProを使用するために必要

public class MoveAndDisappear1 : MonoBehaviour
{
    public Vector3 startPosition; // 開始位置
    public Vector3 targetPosition; // 目標位置
    public float speed = 1.0f; // 移動速度

    public TextMeshProUGUI messageText; // 任意のテキストを表示するためのTextMeshProコンポーネント
    public TextMeshProUGUI sourceText; // メッセージ内容を取得するためのTextMeshProコンポーネント

    private bool isMoving = true; // 移動中かどうかのフラグ
    private const float threshold = 0.001f; // 目標位置への到達を判断する閾値

    public GameObject prefabToSpawn;
    public AudioSource BGM1;
    public AudioSource BGM2;

    void Start()
    {
        // スプライトを開始位置に設定
        transform.position = startPosition;

        // メッセージテキストを非表示に設定
        if (messageText != null)
        {
            messageText.gameObject.SetActive(false);
        }
    }

    void Update()
    {
        if (isMoving)
        {
            // スプライトを目標位置に向かって移動
            float step = speed * Time.deltaTime;
            transform.position = Vector3.MoveTowards(transform.position, targetPosition, step);

            // スプライトが目標位置に到達したかをチェック
            if (Vector3.Distance(transform.position, targetPosition) < threshold)
            {
                // スプライトを非アクティブ化
                gameObject.SetActive(false);
                isMoving = false;
                SpawnPrefab();
                BGM1.Play();
                BGM2.Play();

                // メッセージを表示
                if (messageText != null && sourceText != null)
                {
                    messageText.text = sourceText.text; // 既存オブジェクトからメッセージ内容を取得
                    messageText.gameObject.SetActive(true);
                }
            }
        }
    }
    void SpawnPrefab()
    {
        // Prefabが指定されているかを確認し、Prefabを生成
        if (prefabToSpawn != null)
        {
            Instantiate(prefabToSpawn, targetPosition, Quaternion.identity);
        }
        else
        {
            Debug.LogWarning("Prefab to spawn is not assigned!");
        }
    }
}
