using UnityEngine;

public class ObjectMover : MonoBehaviour
{
    private Transform targetPoint; // 移動の目標地点
    private float speed; // 移動速度
    private Draggable draggable; // ドラッグ可能なコンポーネント

    private Vector3 startPosition; // 初期位置
    private bool returningToPath = false; // パスに戻るフラグ

    public void Initialize(Transform target, float moveSpeed)
    {
        targetPoint = target;
        speed = moveSpeed;
        draggable = GetComponent<Draggable>();
        startPosition = transform.position;
    }

    void Update()
    {
        // ドラッグ中は移動しない
        if (draggable != null && draggable.IsDragging)
        {
            returningToPath = false; // ドラッグ中はパスに戻らない
            return; // ドラッグ中は何もしない
        }

        // パスに戻るフラグが立っているか、目標地点に非常に近づいた場合
        if (returningToPath || (targetPoint != null && Vector3.Distance(transform.position, targetPoint.position) < 0.001f))
        {
            MoveTowards(targetPoint.position); // 目標地点に向かって移動する
        }
        else
        {
            startPosition = transform.position; // 初期位置を更新
        }
    }

    // マウスを離したときの処理
    void OnMouseUp()
    {
        returningToPath = true; // パスに戻るフラグを立てる
    }

    // 指定された目標地点に向かって移動する関数
    private void MoveTowards(Vector3 target)
    {
        float step = speed * Time.deltaTime;
        transform.position = Vector3.MoveTowards(transform.position, target, step); // 目標地点に向かって移動する

        // 目標地点に非常に近づいたら
        if (Vector2.Distance(transform.position, target) < 0.01f)
        {   
           
            if (returningToPath)
            {
                returningToPath = false; // パスに戻るフラグを解除
                
            }
            else if (target == targetPoint.position)
            {
                Destroy(gameObject); // 目標地点に到達したら自身を破棄する
            }
        }
    }
}