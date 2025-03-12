using UnityEngine;
using TMPro; // TextMeshProを使用するために必要
using System.Collections;

public class EndSceneManager : MonoBehaviour
{
    public TextMeshProUGUI scoreText;

    private float displayDuration = 2.0f; // カウントアップにかける時間

    void Start()
    {
        // 初期化
        scoreText.text = "0";

        // スコアを計算
        int finalScore = (int)(GameManager.playerYPosition * GameManager.playerTime * GameManager.playerScale);

        // スコアのカウントアップのコルーチンを開始
        StartCoroutine(CountUpScore(finalScore, displayDuration, scoreText));
    }

    IEnumerator CountUpScore(float targetValue, float duration, TextMeshProUGUI textComponent)
    {
        float startValue = 0;
        float elapsedTime = 0;

        while (elapsedTime < duration)
        {
            elapsedTime += Time.deltaTime;
            float currentValue = Mathf.Lerp(startValue, targetValue, elapsedTime / duration);
            textComponent.text = currentValue.ToString("F0");
            yield return null;
        }

        // 最終的なスコアを設定
        textComponent.text = targetValue.ToString("F0");
    }
}
