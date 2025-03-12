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
            // ターゲットポイントに向かって移動する
            float step = speed * Time.deltaTime;
            transform.position = Vector2.MoveTowards(transform.position, target.position, step);

            // オブジェクトがターゲットに近づいたかどうかをチェック
            if (Vector2.Distance(transform.position, target.position) < ThresholdDistance)
            {
                ScoreManager.Instance.SubScore(); // スコアを減算する
                Destroy(gameObject);
            }
        }
    }
}
