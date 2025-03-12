using UnityEngine;

public class Draggable : MonoBehaviour
{
    private Vector2 offset;
    private Camera mainCamera;
    private bool isDragging = false;
    private Vector2 startDragPosition;
    public bool IsDragging => isDragging;

    private Vector2 originalScale;
    private Vector2 enlargedScale;

    private Transform currentCan; // ���݂̃S�~��

    void Start()
    {
        mainCamera = Camera.main;
        originalScale = new Vector2(0.7f, 0.7f);
        enlargedScale = originalScale * 1.2f; // �g�傷��T�C�Y��ݒ�
    }

    void OnMouseDown()
    {
        if (mainCamera == null)
        {
            mainCamera = Camera.main;
        }
        offset = (Vector2)transform.position - GetMouseWorldPos();
        isDragging = true;
        startDragPosition = transform.position; // �h���b�O�J�n���̈ʒu��ۑ�

        EnlargeIfOver();
    }

    void OnMouseDrag()
    {
        transform.position = GetMouseWorldPos() + offset;
        EnlargeIfOver();
    }

    void OnMouseUp()
    {
        isDragging = false;
        CheckDropLocation(); // �h���b�v���Ɉʒu���`�F�b�N

        // �h���b�O�I�����Ɍ��̃T�C�Y�ɖ߂�
        if (currentCan != null)
        {
            currentCan.localScale = originalScale;
            currentCan = null;
        }
    }

    Vector2 GetMouseWorldPos()
    {
        Vector3 mousePoint = Input.mousePosition;
        mousePoint.z = mainCamera.WorldToScreenPoint(gameObject.transform.position).z;
        return mainCamera.ScreenToWorldPoint(mousePoint);
    }

    void CheckDropLocation()
{
    Collider2D[] hitColliders = Physics2D.OverlapCircleAll(transform.position, 0.5f);
    bool droppedInCorrectCan = false;
    bool overCan = false;

    foreach (var hitCollider in hitColliders)
    {
        if (IsCan(hitCollider.name))
        {
            overCan = true;

            if ((hitCollider.name == "GarbageCan" && gameObject.CompareTag("Garbage")) ||
                (hitCollider.name == "NotGarbageCan" && gameObject.CompareTag("NotGarbage")) ||
                (hitCollider.name == "PaperCan" && gameObject.CompareTag("Paper")) ||
                (hitCollider.name == "PlasticCan" && gameObject.CompareTag("Plastic")) ||
                (hitCollider.name == "SpecificCan" && gameObject.CompareTag("Specific")) ||
                (hitCollider.name == "BottleCan" && gameObject.CompareTag("Bottle")))
            {
                droppedInCorrectCan = true;
                Destroy(gameObject); // �������S�~���Ƀh���b�v�����ꍇ�A�S�~��j��
                ScoreManager.Instance.AddScore(); // �X�R�A�𑝉�
                return;
            }
        } else {
            overCan = false;
        }
    }

    if (!droppedInCorrectCan && overCan)
    {
        // ������S�~���ɓ��ꂽ�ꍇ
        ScoreManager.Instance.SubScore(); // �X�R�A������
        Destroy(gameObject); // ������S�~���Ƀh���b�v�����ꍇ�A�S�~��j��
    }
    else
    {
        // �S�~���ȊO�̏ꏊ�Ƀh���b�v�����ꍇ
        transform.position = startDragPosition; // ���̈ʒu�ɖ߂�
    }
}


    bool IsCan(string name)
    {
        // �S�~���̖��O�Ɋ�Â��Ĕ��肷��
        return name.EndsWith("Can");
    }

    void EnlargeIfOver()
    {
        // �h���b�O���ɃS�~����ɂ��邩�ǂ������`�F�b�N
        Collider2D[] hitColliders = Physics2D.OverlapCircleAll(transform.position, 0.5f);
        bool overCan = false;

        foreach (var hitCollider in hitColliders)
        {
            if (IsCan(hitCollider.name))
            {
                overCan = true;

                // �V�����S�~���ɓ������ꍇ�A�O�̃S�~���̃T�C�Y�����ɖ߂�
                if (currentCan != null && currentCan != hitCollider.transform)
                {
                    currentCan.localScale = originalScale;
                }

                // �V�����S�~�����g�傷��
                hitCollider.transform.localScale = enlargedScale;
                currentCan = hitCollider.transform;

                break; // ��̃S�~���ɂ̂ݑΉ����邽�߁A�����𔲂���
            }
        }

        // �S�~����ɂȂ��ꍇ�A���̃T�C�Y�ɖ߂�
        if (!overCan && currentCan != null)
        {
            currentCan.localScale = originalScale;
            currentCan = null;
        }
    }
}
