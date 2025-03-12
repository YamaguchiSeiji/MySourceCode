using UnityEngine;

public class BackgroundSwitcher : MonoBehaviour
{
    public GameObject[] backgrounds; // �w�i�I�u�W�F�N�g�̔z��
    public float fadeDuration = 1f; // �t�F�[�h�C���E�t�F�[�h�A�E�g�̎���

    private int currentIndex = 0;
    private float timer = 0f;
    private bool isFading = false;

    void Start()
    {
        // �ŏ��̔w�i�ȊO���\���ɂ���
        for (int i = 1; i < backgrounds.Length; i++)
        {
            backgrounds[i].SetActive(false);
        }
    }

    void Update()
    {
        timer += Time.deltaTime;

        if (!isFading)
        {
            if (timer >= 6f && timer < 12f && currentIndex == 0)
            {
                StartCoroutine(SwitchBackground(1));
            }
            else if (timer >= 12f && timer < 18f && currentIndex == 1)
            {
                StartCoroutine(SwitchBackground(2));
            }
            else if(timer >= 18f && currentIndex == 2)
            {
                StartCoroutine(SwitchBackground(0));
                timer = 0f;
            }
        }
    }

    System.Collections.IEnumerator SwitchBackground(int index)
    {
        isFading = true;

        // �t�F�[�h�A�E�g
        yield return StartCoroutine(FadeOut(currentIndex));

        // �w�i�̐؂�ւ�
        backgrounds[currentIndex].SetActive(false);
        backgrounds[index].SetActive(true);
        currentIndex = index;

        // �t�F�[�h�C��
        yield return StartCoroutine(FadeIn(index));

        isFading = false;
    }

    System.Collections.IEnumerator FadeOut(int index)
    {
        SpriteRenderer spriteRenderer = backgrounds[index].GetComponent<SpriteRenderer>();
        if (spriteRenderer == null)
        {
            yield break;
        }

        Color startColor = spriteRenderer.color;
        float elapsedTime = 0f;

        while (elapsedTime < fadeDuration)
        {
            elapsedTime += Time.deltaTime;
            float alpha = Mathf.Lerp(startColor.a, 0, elapsedTime / fadeDuration);
            spriteRenderer.color = new Color(startColor.r, startColor.g, startColor.b, alpha);
            yield return null;
        }

        spriteRenderer.color = new Color(startColor.r, startColor.g, startColor.b, 0);
    }

    System.Collections.IEnumerator FadeIn(int index)
    {
        SpriteRenderer spriteRenderer = backgrounds[index].GetComponent<SpriteRenderer>();
        if (spriteRenderer == null)
        {
            yield break;
        }

        Color startColor = spriteRenderer.color;
        startColor.a = 0;
        spriteRenderer.color = startColor;

        float elapsedTime = 0f;

        while (elapsedTime < fadeDuration)
        {
            elapsedTime += Time.deltaTime;
            float alpha = Mathf.Lerp(0, 1, elapsedTime / fadeDuration);
            spriteRenderer.color = new Color(startColor.r, startColor.g, startColor.b, alpha);
            yield return null;
        }

        spriteRenderer.color = new Color(startColor.r, startColor.g, startColor.b, 1);
    }
}
