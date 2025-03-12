using UnityEngine;
using TMPro; // TextMeshPro���g�p���邽�߂ɕK�v

public class MoveAndDisappear1 : MonoBehaviour
{
    public Vector3 startPosition; // �J�n�ʒu
    public Vector3 targetPosition; // �ڕW�ʒu
    public float speed = 1.0f; // �ړ����x

    public TextMeshProUGUI messageText; // �C�ӂ̃e�L�X�g��\�����邽�߂�TextMeshPro�R���|�[�l���g
    public TextMeshProUGUI sourceText; // ���b�Z�[�W���e���擾���邽�߂�TextMeshPro�R���|�[�l���g

    private bool isMoving = true; // �ړ������ǂ����̃t���O
    private const float threshold = 0.001f; // �ڕW�ʒu�ւ̓��B�𔻒f����臒l

    public GameObject prefabToSpawn;
    public AudioSource BGM1;
    public AudioSource BGM2;

    void Start()
    {
        // �X�v���C�g���J�n�ʒu�ɐݒ�
        transform.position = startPosition;

        // ���b�Z�[�W�e�L�X�g���\���ɐݒ�
        if (messageText != null)
        {
            messageText.gameObject.SetActive(false);
        }
    }

    void Update()
    {
        if (isMoving)
        {
            // �X�v���C�g��ڕW�ʒu�Ɍ������Ĉړ�
            float step = speed * Time.deltaTime;
            transform.position = Vector3.MoveTowards(transform.position, targetPosition, step);

            // �X�v���C�g���ڕW�ʒu�ɓ��B���������`�F�b�N
            if (Vector3.Distance(transform.position, targetPosition) < threshold)
            {
                // �X�v���C�g���A�N�e�B�u��
                gameObject.SetActive(false);
                isMoving = false;
                SpawnPrefab();
                BGM1.Play();
                BGM2.Play();

                // ���b�Z�[�W��\��
                if (messageText != null && sourceText != null)
                {
                    messageText.text = sourceText.text; // �����I�u�W�F�N�g���烁�b�Z�[�W���e���擾
                    messageText.gameObject.SetActive(true);
                }
            }
        }
    }
    void SpawnPrefab()
    {
        // Prefab���w�肳��Ă��邩���m�F���APrefab�𐶐�
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
