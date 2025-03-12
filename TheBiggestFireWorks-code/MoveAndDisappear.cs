using UnityEngine;
using UnityEngine.UI;

public class MoveAndDisappear : MonoBehaviour
{
    private Camera mainCamera;
    private Vector3 targetPosition;
    private bool isMoving = false;
    public float playerScale = 2.0f;

    public GameObject prefab2_2_2_5; // �X�P�[����2f����2.5f�̂Ƃ��ɐ�������v���n�u
    public GameObject prefab2_5_3;   // �X�P�[����2.5f����3f�̂Ƃ��ɐ�������v���n�u
    public GameObject prefab3_3_5;   // �X�P�[����3f����3.5f�̂Ƃ��ɐ�������v���n�u
    public GameObject prefab3_5_4;   // �X�P�[����3.5f����4f�̂Ƃ��ɐ�������v���n�u
    public GameObject prefab4_4_5;   // �X�P�[����4f����4.5f�̂Ƃ��ɐ�������v���n�u

    public GameObject confirmationPanel;

    void Start()
    {
        mainCamera = Camera.main;
        targetPosition = mainCamera.ViewportToWorldPoint(new Vector3(0.5f, 0.5f + 0.1f, 10f)); // ��ʒ����̃��[���h���W���擾
        playerScale = GameManager.playerScale;
        transform.localScale = new Vector3(playerScale, playerScale, playerScale);
        confirmationPanel.SetActive(false);
    }

    void Update()
    {
        if (!isMoving)
        {
            MoveToCenter();
        }
    }

    void MoveToCenter()
    {
        transform.position = Vector3.MoveTowards(transform.position, targetPosition, Time.deltaTime * 5f);

        if (transform.position == targetPosition)
        {
            // ��ʒ����ɓ��B������I�u�W�F�N�g���A�N�e�B�u�ɂ���i������j
            gameObject.SetActive(false);

            // �v���C���[�X�P�[���̎擾
            float scale = transform.localScale.x;

            // �X�P�[���ɉ����ăI�u�W�F�N�g����
            if (scale < 3f)
            {
                // �X�P�[����2f����2.5f�̂Ƃ��ɐ�������I�u�W�F�N�g�𐶐�
                Instantiate(prefab2_2_2_5, transform.position, transform.rotation);
            }
            else if (scale >= 3f && scale < 4f)
            {
                // �X�P�[����2.5f����3f�̂Ƃ��ɐ�������I�u�W�F�N�g�𐶐�
                Instantiate(prefab2_5_3, transform.position, transform.rotation);
            }
            else if (scale >= 4f && scale < 5f)
            {
                // �X�P�[����3f����3.5f�̂Ƃ��ɐ�������I�u�W�F�N�g�𐶐�
                Instantiate(prefab3_3_5, transform.position, transform.rotation);
            }
            else if (scale >= 5f && scale < 6f)
            {
                // �X�P�[����3.5f����4f�̂Ƃ��ɐ�������I�u�W�F�N�g�𐶐�
                Instantiate(prefab3_5_4, transform.position, transform.rotation);
            }
            else if (scale >= 6f)
            {
                // �X�P�[����4f����4.5f�̂Ƃ��ɐ�������I�u�W�F�N�g�𐶐�
                Instantiate(prefab4_4_5, transform.position, transform.rotation);
            }

            CreatePanel();

        }
    }

    void OnBecameInvisible()
    {
        // ��ʊO�ɏo����I�u�W�F�N�g���A�N�e�B�u�ɂ���i������j
        gameObject.SetActive(false);
    }

    void CreatePanel()
    {
        confirmationPanel.SetActive(true);
    }
}
