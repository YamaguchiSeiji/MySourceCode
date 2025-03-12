using System.Collections;
using UnityEngine;

public class BackgroundColorChanger : MonoBehaviour
{
    // 色の変更タイミングと対応する色の配列
    private static readonly float[] colorChangeTimings = { 15f, 25f, 35f, 45f };
    private static readonly Color[] targetColors = { new Color(0.92f, 0.92f, 1f), new Color(0.376f, 1f, 1f), new Color(1f, 0.529f, 0f), new Color(0.094f, 0.012f, 0.337f), new Color(0.035f, 0f, 0.145f) }; // 新しい色に変更

    private static Color initialColor;

    public static float startTime = -1f;

    // ゲーム開始時に色の変更を開始する
    void Start()
    {
        if (startTime < 0f)
        {
            startTime = Time.time; // 最初のオブジェクトの開始時間を記録
        }

        initialColor = GetComponent<SpriteRenderer>().color;
        StartCoroutine(ChangeColorOverTime());
    }

    // 色を変更するコルーチン
    IEnumerator ChangeColorOverTime()
    {
        for (int i = 0; i < colorChangeTimings.Length; i++)
        {
            float startTimeForColor = startTime;

            while (Time.time - startTimeForColor < colorChangeTimings[i])
            {
                float t = (Time.time - startTimeForColor) / colorChangeTimings[i];
                GetComponent<SpriteRenderer>().color = Color.Lerp(initialColor, targetColors[i], t);
                yield return null;
            }

            // 最終的な色を設定
            GetComponent<SpriteRenderer>().color = targetColors[i];
        }
    }
}