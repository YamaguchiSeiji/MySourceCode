using UnityEngine;

public class ObjectSpawner : MonoBehaviour
{
    public GameObject[] objectPrefabs; // ��������I�u�W�F�N�g�̃v���n�u�̃��X�g
    public Transform spawnPoint; // ��������ʒu
    public Transform targetPoint; // ������ʒu
    public float initialSpawnInterval = 2.0f; // ���������Ԋu�i�b�j
    public float initialSpeed = 2.0f; // �����ړ����x
    public float minSpawnInterval = 0.3f; // �ŏ������Ԋu�i�b�j
    public float maxSpeed = 10.0f; // �ő呬�x
    public float speedIncrement = 0.1f; // ���x������
    public float spawnIntervalDecrement = 0.1f; // �����Ԋu������
    public float speedDecreaseOnMiss = 0.3f; // �~�X���̑��x������
    public float spawnIntervalDecrementOnMiss = 0.2f; // �~�X���̐����Ԋu������

    private float spawnInterval; // ���݂̐����Ԋu
    private float speed; // ���݂̈ړ����x
    private float timer;

    private float initialMovementSpeed; // �����ړ����x��ێ����邽�߂̕ϐ�

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
        initialMovementSpeed = initialSpeed; // �����ړ����x��ۑ�
        timer = spawnInterval; // �^�C�}�[�����������Ԋu�ɐݒ�
    }

    void Update()
    {
        timer -= Time.deltaTime; // �^�C�}�[������������

        if (timer <= 0f)
        {
            SpawnObject(); // �^�C�}�[��0�ȉ��ɂȂ�����I�u�W�F�N�g�𐶐�
            timer = spawnInterval; // �^�C�}�[�����Z�b�g
        }

        // �X�R�A�ɉ����Đ����Ԋu�𒲐�����
        if (ScoreManager.Instance != null)
        {
            int score = ScoreManager.Instance.score;
            float scoreFactor = Mathf.Max(0, score / 100f);

            float newSpawnInterval = initialSpawnInterval - scoreFactor * spawnIntervalDecrement;
            spawnInterval = Mathf.Max(minSpawnInterval, newSpawnInterval); // �X�R�A�ɉ����Đ����Ԋu�𒲐�
        }
    }

    void SpawnObject()
    {
        if (objectPrefabs != null && objectPrefabs.Length > 0 && spawnPoint != null)
        {
            int randomIndex = Random.Range(0, objectPrefabs.Length);
            GameObject spawnedObject = Instantiate(objectPrefabs[randomIndex], spawnPoint.position, Quaternion.identity);

            // Draggable���Ȃ���Βǉ�
            if (spawnedObject.GetComponent<Draggable>() == null)
            {
                spawnedObject.AddComponent<Draggable>();
            }

            // ConveyorMover���Ȃ���Βǉ����ď�����
            ConveyorMover mover = spawnedObject.GetComponent<ConveyorMover>();
            if (mover == null)
            {
                mover = spawnedObject.AddComponent<ConveyorMover>();
            }
            mover.Initialize(targetPoint, speed);
        }
        else
        {
            Debug.LogError("ObjectPrefabs ���ݒ肳��Ă��Ȃ����A��ł��B�܂��� SpawnPoint ���ݒ肳��Ă��܂���");
        }
    }

    // �X�R�A�ɉ����đ��x�𑝉�������֐�
    public void IncreaseSpeedWithScore()
    {
        speed = Mathf.Min(maxSpeed, speed + speedIncrement); // ���ʂ̑��x�����Z���A�ő呬�x�𒴂��Ȃ��悤�ɂ���
    }

    // �~�X���ɌĂ΂��֐�
    public void OnMiss()
    {
        // �����Ԋu�𑝂₷
        spawnInterval += spawnIntervalDecrementOnMiss;

        // ���������Ԋu�𒴂��Ȃ��悤�ɒ���
        spawnInterval = Mathf.Min(initialSpawnInterval, spawnInterval);

        // �ړ����x������������
        speed -= speedDecreaseOnMiss;

        // �����ړ����x�ȉ��ɂȂ�Ȃ��悤�ɒ���
        speed = Mathf.Max(initialMovementSpeed, speed);
    }

    public void ResetSpawnIntervalAndSpeed()
    {
        // �����Ԋu�Ƒ��x�������ݒ�l�Ƀ��Z�b�g���鏈��
        spawnInterval = initialSpawnInterval;
        speed = initialSpeed;
    }
}
