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

    private Transform currentCan; // 現在のゴミ箱

    void Start()
    {
        mainCamera = Camera.main;
        originalScale = new Vector2(0.7f, 0.7f);
        enlargedScale = originalScale * 1.2f; // 拡大するサイズを設定
    }

    void OnMouseDown()
    {
        if (mainCamera == null)
        {
            mainCamera = Camera.main;
        }
        offset = (Vector2)transform.position - GetMouseWorldPos();
        isDragging = true;
        startDragPosition = transform.position; // ドラッグ開始時の位置を保存

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
        CheckDropLocation(); // ドロップ時に位置をチェック

        // ドラッグ終了時に元のサイズに戻す
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
                Destroy(gameObject); // 正しいゴミ箱にドロップした場合、ゴミを破棄
                ScoreManager.Instance.AddScore(); // スコアを増加
                return;
            }
        } else {
            overCan = false;
        }
    }

    if (!droppedInCorrectCan && overCan)
    {
        // 誤ったゴミ箱に入れた場合
        ScoreManager.Instance.SubScore(); // スコアを減少
        Destroy(gameObject); // 誤ったゴミ箱にドロップした場合、ゴミを破棄
    }
    else
    {
        // ゴミ箱以外の場所にドロップした場合
        transform.position = startDragPosition; // 元の位置に戻す
    }
}


    bool IsCan(string name)
    {
        // ゴミ箱の名前に基づいて判定する
        return name.EndsWith("Can");
    }

    void EnlargeIfOver()
    {
        // ドラッグ中にゴミ箱上にいるかどうかをチェック
        Collider2D[] hitColliders = Physics2D.OverlapCircleAll(transform.position, 0.5f);
        bool overCan = false;

        foreach (var hitCollider in hitColliders)
        {
            if (IsCan(hitCollider.name))
            {
                overCan = true;

                // 新しいゴミ箱に入った場合、前のゴミ箱のサイズを元に戻す
                if (currentCan != null && currentCan != hitCollider.transform)
                {
                    currentCan.localScale = originalScale;
                }

                // 新しいゴミ箱を拡大する
                hitCollider.transform.localScale = enlargedScale;
                currentCan = hitCollider.transform;

                break; // 一つのゴミ箱にのみ対応するため、処理を抜ける
            }
        }

        // ゴミ箱上にない場合、元のサイズに戻す
        if (!overCan && currentCan != null)
        {
            currentCan.localScale = originalScale;
            currentCan = null;
        }
    }
}
