using UnityEngine;

public class ObjectMover : MonoBehaviour
{
    private Transform targetPoint; // �ړ��̖ڕW�n�_
    private float speed; // �ړ����x
    private Draggable draggable; // �h���b�O�\�ȃR���|�[�l���g

    private Vector3 startPosition; // �����ʒu
    private bool returningToPath = false; // �p�X�ɖ߂�t���O

    public void Initialize(Transform target, float moveSpeed)
    {
        targetPoint = target;
        speed = moveSpeed;
        draggable = GetComponent<Draggable>();
        startPosition = transform.position;
    }

    void Update()
    {
        // �h���b�O���͈ړ����Ȃ�
        if (draggable != null && draggable.IsDragging)
        {
            returningToPath = false; // �h���b�O���̓p�X�ɖ߂�Ȃ�
            return; // �h���b�O���͉������Ȃ�
        }

        // �p�X�ɖ߂�t���O�������Ă��邩�A�ڕW�n�_�ɔ��ɋ߂Â����ꍇ
        if (returningToPath || (targetPoint != null && Vector3.Distance(transform.position, targetPoint.position) < 0.001f))
        {
            MoveTowards(targetPoint.position); // �ڕW�n�_�Ɍ������Ĉړ�����
        }
        else
        {
            startPosition = transform.position; // �����ʒu���X�V
        }
    }

    // �}�E�X�𗣂����Ƃ��̏���
    void OnMouseUp()
    {
        returningToPath = true; // �p�X�ɖ߂�t���O�𗧂Ă�
    }

    // �w�肳�ꂽ�ڕW�n�_�Ɍ������Ĉړ�����֐�
    private void MoveTowards(Vector3 target)
    {
        float step = speed * Time.deltaTime;
        transform.position = Vector3.MoveTowards(transform.position, target, step); // �ڕW�n�_�Ɍ������Ĉړ�����

        // �ڕW�n�_�ɔ��ɋ߂Â�����
        if (Vector2.Distance(transform.position, target) < 0.01f)
        {   
           
            if (returningToPath)
            {
                returningToPath = false; // �p�X�ɖ߂�t���O������
                
            }
            else if (target == targetPoint.position)
            {
                Destroy(gameObject); // �ڕW�n�_�ɓ��B�����玩�g��j������
            }
        }
    }
}