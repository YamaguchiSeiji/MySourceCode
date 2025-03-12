using UnityEngine;

public class RandomChildSprite : MonoBehaviour
{
    // ランダム化したい子Spriteの配列
    public SpriteRenderer[] childSprites;

    void Start()
    {
        // 子Spriteが1つ以上あるかを確認
        if (childSprites.Length > 0)
        {
            // ランダムなインデックスを選択
            int randomIndex = Random.Range(0, childSprites.Length);

            // 選択された子Spriteを表示し、それ以外の子Spriteを非表示にする
            for (int i = 0; i < childSprites.Length; i++)
            {
                childSprites[i].gameObject.SetActive(i == randomIndex);
            }

            // ランダムな座標を生成
            float randomX = Random.Range(-0.5f, 0.5f);
            float randomY = Random.Range(-0.5f, 0.5f); // y座標は-0.5fから0.5fの範囲でランダム

            // スケールの比率を保持しつつ、ランダムなスケールを設定
            float randomScale = Random.Range(0.5f, 1f); // 0.5から1の範囲でランダムなスケールを生成

            // ランダムな座標に各子Spriteを移動
            foreach (SpriteRenderer childSprite in childSprites)
            {
                // スケールの比率を保持しつつ、ランダムなスケールを設定
                childSprite.transform.localScale = new Vector3(childSprite.transform.localScale.x * randomScale, childSprite.transform.localScale.y * randomScale, childSprite.transform.localScale.z);

                // 座標を設定
                childSprite.transform.localPosition = new Vector3(randomX, randomY, childSprite.transform.localPosition.z);
            }
        }
    }
}
