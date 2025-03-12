using UnityEngine;

public class ConveyorMover : MonoBehaviour
{
    private Transform target;
    private float speed;
    private const float ThresholdDistance = 0.1f;

    public void Initialize(Transform targetPoint, float moveSpeed)
    {
        target = targetPoint;
        speed = moveSpeed;
    }

    void Update()
    {
        if (target != null)
        {
            // �^�[�Q�b�g�|�C���g�Ɍ������Ĉړ�����
            float step = speed * Time.deltaTime;
            transform.position = Vector2.MoveTowards(transform.position, target.position, step);

            // �I�u�W�F�N�g���^�[�Q�b�g�ɋ߂Â������ǂ������`�F�b�N
            if (Vector2.Distance(transform.position, target.position) < ThresholdDistance)
            {
                ScoreManager.Instance.SubScore(); // �X�R�A�����Z����
                Destroy(gameObject);
            }
        }
    }
}
