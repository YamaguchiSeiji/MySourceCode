using System.Collections;
using TMPro;
using UnityEngine;

public class TimerController : MonoBehaviour
{
    public TMP_Text timerText;
    private int countdownTime = 3;
    private int gameTime = 0; // ゲーム時間の初期値 (秒)
    private bool isGameRunning = false;

    void Start()
    {
        StartCoroutine(StartCountdown());
    }

    IEnumerator StartCountdown()
    {
        Time.timeScale = 0; // ゲームを停止

        while (countdownTime > 0)
        {
            timerText.text = countdownTime.ToString();
            yield return new WaitForSecondsRealtime(1f); // リアルタイムでの待機
            countdownTime--;
        }

        timerText.text = "スタート";
        yield return new WaitForSecondsRealtime(1f); // "ゲームスタート!!" を1秒間表示

        Time.timeScale = 1; // ゲームを再開
        StartCoroutine(StartGameTimer());
    }

    IEnumerator StartGameTimer()
    {
        isGameRunning = true;

        while (true) // ゲーム時間が制限なしで増加するループ
        {
            yield return new WaitForSeconds(1f);
            gameTime++;

            UpdateTimerDisplay();

            // ここに必要なゲームの処理を追加できます
        }
    }

    void UpdateTimerDisplay()
    {
        timerText.text = gameTime.ToString();
    }

    void EndGame()
    {
        isGameRunning = false;
        // ゲーム終了時の処理をここに追加
    }
}
