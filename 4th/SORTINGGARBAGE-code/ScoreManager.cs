using UnityEngine;
using TMPro;
using DG.Tweening;

public class ScoreManager : MonoBehaviour
{
    // シングルトンインスタンス
    public static ScoreManager Instance { get; private set; }

    // スコアを表示するTextMeshProの参照
    public TextMeshProUGUI scoreText;
    // MISSメッセージを表示するTextMeshProの参照
    public TextMeshProUGUI missText;
    // コンボを表示するTextMeshProの参照
    public TextMeshProUGUI comboText;

    // 現在のスコア (public でアクセス可能にする)
    public int score = 0;
    // ミス回数
    private int missCount = 0;
    // 最大ミス回数
    private const int maxMissCount = 3;

    // コンボ関連
    private int comboCount = 0; // コンボカウント
    private float comboMultiplier = 1.0f; // コンボ倍率

    private const int initialScoreAmount = 100; // 初期加算スコア

    void Awake()
    {
        // シングルトンインスタンスの設定
        if (Instance == null)
        {
            Instance = this;
            DontDestroyOnLoad(gameObject); // シーン間でオブジェクトを破棄しない
        }
        else
        {
            Destroy(gameObject); // すでにインスタンスがある場合は、このオブジェクトを破棄
        }
    }

    void Start()
    {
        UpdateScoreText();
        missText.gameObject.SetActive(false); // 初期状態では非表示
        comboText.gameObject.SetActive(false); // 初期状態では非表示
    }

    // スコアを加算する関数
    public void AddScore()
    {
        comboCount++;
        comboMultiplier = 1.0f + 0.5f * comboCount; // コンボ倍率を更新
        int finalScoreAmount = Mathf.RoundToInt(initialScoreAmount * comboMultiplier);
        score += finalScoreAmount;
        ObjectSpawner.Instance.IncreaseSpeedWithScore(); // スコアが増加した際の速度更新
        UpdateScoreText();
        ShowComboMessage();
    }

    // スコアを減算する関数
    public void SubScore()
    {
        score -= initialScoreAmount;
        comboCount = 0; // コンボをリセット
        comboMultiplier = 1.0f; // コンボ倍率をリセット

        missCount++; // ミスカウントを増やす
        if (missCount >= maxMissCount)
        {
            EndGame(); // 最大ミス回数に達したらゲーム終了
        }
        else
        {
            ShowMissMessage();
        }

        UpdateScoreText();
        HideComboMessage();
    }

    // スコアをTextMeshProに表示する関数
    void UpdateScoreText()
    {
        scoreText.text = "スコア: " + score.ToString();
        if (score < 0)
        {
            scoreText.color = Color.red;
        }
        else
        {
            scoreText.color = Color.black;
        }
    }

    // MISSメッセージをふわっと表示する関数
    void ShowMissMessage()
    {
        missText.gameObject.SetActive(true);
        missText.text = "ミス";
        missText.color = Color.red;

        // フェードインアニメーション
        missText.transform.localScale = Vector3.zero;
        missText.transform.DOScale(1f, 0.2f).SetEase(Ease.OutBack);
        missText.DOFade(1f, 0.2f).SetEase(Ease.OutQuad);

        // 2秒後に非表示にする
        Invoke("HideMissMessage", 1f);
    }

    void HideMissMessage()
    {
        // フェードアウトアニメーション
        missText.DOFade(0f, 0.2f).SetEase(Ease.InQuad).OnComplete(() =>
        {
            missText.gameObject.SetActive(false);
        });
    }

    // コンボメッセージを表示する関数
    void ShowComboMessage()
    {
        comboText.gameObject.SetActive(true);
        comboText.text = "コンボ x" + comboCount.ToString();
        comboText.color = Color.green;

        // フェードインアニメーション
        comboText.transform.localScale = Vector3.zero;
        comboText.transform.DOScale(1f, 0.2f).SetEase(Ease.OutBack);
        comboText.DOFade(1f, 0.2f).SetEase(Ease.OutQuad);
    }

    void HideComboMessage()
    {
        // フェードアウトアニメーション
        comboText.DOFade(0f, 0.2f).SetEase(Ease.InQuad).OnComplete(() =>
        {
            comboText.gameObject.SetActive(false);
        });
    }

    // ゲーム終了処理
    void EndGame()
    {
        Debug.Log("Game Over - Too many misses!");
        // ゲーム終了処理をここに追加する（例えばシーンのリロード、終了処理など）
        // この例ではエディタでの実行時には停止する
#if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;
#else
        Application.Quit(); // ビルドしたアプリケーションでは終了する
#endif
    }
}
