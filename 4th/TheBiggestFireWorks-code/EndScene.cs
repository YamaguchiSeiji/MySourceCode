using UnityEngine;
using TMPro; // TextMeshPro���g�p���邽�߂ɕK�v
using System.Collections;

public class EndSceneManager : MonoBehaviour
{
    public TextMeshProUGUI scoreText;

    private float displayDuration = 2.0f; // �J�E���g�A�b�v�ɂ����鎞��

    void Start()
    {
        // ������
        scoreText.text = "0";

        // �X�R�A���v�Z
        int finalScore = (int)(GameManager.playerYPosition * GameManager.playerTime * GameManager.playerScale);

        // �X�R�A�̃J�E���g�A�b�v�̃R���[�`�����J�n
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

        // �ŏI�I�ȃX�R�A��ݒ�
        textComponent.text = targetValue.ToString("F0");
    }
}
