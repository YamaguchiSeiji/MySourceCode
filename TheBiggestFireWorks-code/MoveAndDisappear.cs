using UnityEngine;
using UnityEngine.UI;

public class MoveAndDisappear : MonoBehaviour
{
    private Camera mainCamera;
    private Vector3 targetPosition;
    private bool isMoving = false;
    public float playerScale = 2.0f;

    public GameObject prefab2_2_2_5; // スケールが2fから2.5fのときに生成するプレハブ
    public GameObject prefab2_5_3;   // スケールが2.5fから3fのときに生成するプレハブ
    public GameObject prefab3_3_5;   // スケールが3fから3.5fのときに生成するプレハブ
    public GameObject prefab3_5_4;   // スケールが3.5fから4fのときに生成するプレハブ
    public GameObject prefab4_4_5;   // スケールが4fから4.5fのときに生成するプレハブ

    public GameObject confirmationPanel;

    void Start()
    {
        mainCamera = Camera.main;
        targetPosition = mainCamera.ViewportToWorldPoint(new Vector3(0.5f, 0.5f + 0.1f, 10f)); // 画面中央のワールド座標を取得
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
            // 画面中央に到達したらオブジェクトを非アクティブにする（消える）
            gameObject.SetActive(false);

            // プレイヤースケールの取得
            float scale = transform.localScale.x;

            // スケールに応じてオブジェクト生成
            if (scale < 3f)
            {
                // スケールが2fから2.5fのときに生成するオブジェクトを生成
                Instantiate(prefab2_2_2_5, transform.position, transform.rotation);
            }
            else if (scale >= 3f && scale < 4f)
            {
                // スケールが2.5fから3fのときに生成するオブジェクトを生成
                Instantiate(prefab2_5_3, transform.position, transform.rotation);
            }
            else if (scale >= 4f && scale < 5f)
            {
                // スケールが3fから3.5fのときに生成するオブジェクトを生成
                Instantiate(prefab3_3_5, transform.position, transform.rotation);
            }
            else if (scale >= 5f && scale < 6f)
            {
                // スケールが3.5fから4fのときに生成するオブジェクトを生成
                Instantiate(prefab3_5_4, transform.position, transform.rotation);
            }
            else if (scale >= 6f)
            {
                // スケールが4fから4.5fのときに生成するオブジェクトを生成
                Instantiate(prefab4_4_5, transform.position, transform.rotation);
            }

            CreatePanel();

        }
    }

    void OnBecameInvisible()
    {
        // 画面外に出たらオブジェクトを非アクティブにする（消える）
        gameObject.SetActive(false);
    }

    void CreatePanel()
    {
        confirmationPanel.SetActive(true);
    }
}
