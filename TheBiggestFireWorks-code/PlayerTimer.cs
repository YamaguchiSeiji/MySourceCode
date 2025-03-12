using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class TimeCounter : MonoBehaviour
{
    private SpriteRenderer SpriteRenderer { get; set; }
    [SerializeField] private Renderer _target;

    //カウントダウン
    public float countdown;
    private float _time;
    //時間を表示するText型の変数
    private Text timeText;

    // Update is called once per frame
    void Start()
    {
        SpriteRenderer = GetComponent<SpriteRenderer>();
        countdown = GameController.timer;
    }

    void CountDown()
    {
        //時間をカウントダウンする
        countdown -= Time.deltaTime;

        //countdownが0以下になったとき
        if (countdown <= 0)
        {
            GameManager.GameOver();
        }
        else if (countdown <= 2)
        {
            LightBlinking(0.1f);
        }
        else if (countdown <= 5)
        {
            LightBlinking(0.5f);
        }
        else if (countdown <= 10)
        {
            LightBlinking(1.0f);
        } else
        {
            SpriteRenderer.color = new Color(255f, 255f, 255f);
        }
    }

    private void LightBlinking(float interval) {
        // 内部時刻を経過させる
        _time += Time.deltaTime;

        // 周期cycleで繰り返す値の取得
        // 0～cycleの範囲の値が得られる
        var repeatValue = Mathf.Repeat((float)_time, interval);

        // 内部時刻timeにおける明滅状態を反映
        if (repeatValue >= interval * 0.5f)
        {
            SpriteRenderer.color = new Color(255f, 0f, 0f);
        }
        else
        {
            SpriteRenderer.color = new Color(255f, 255f, 255f);
        }
    }
}