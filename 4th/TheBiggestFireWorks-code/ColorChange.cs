using System.Collections;
using UnityEngine;

public class BackgroundColorChanger : MonoBehaviour
{
    // �F�̕ύX�^�C�~���O�ƑΉ�����F�̔z��
    private static readonly float[] colorChangeTimings = { 15f, 25f, 35f, 45f };
    private static readonly Color[] targetColors = { new Color(0.92f, 0.92f, 1f), new Color(0.376f, 1f, 1f), new Color(1f, 0.529f, 0f), new Color(0.094f, 0.012f, 0.337f), new Color(0.035f, 0f, 0.145f) }; // �V�����F�ɕύX

    private static Color initialColor;

    public static float startTime = -1f;

    // �Q�[���J�n���ɐF�̕ύX���J�n����
    void Start()
    {
        if (startTime < 0f)
        {
            startTime = Time.time; // �ŏ��̃I�u�W�F�N�g�̊J�n���Ԃ��L�^
        }

        initialColor = GetComponent<SpriteRenderer>().color;
        StartCoroutine(ChangeColorOverTime());
    }

    // �F��ύX����R���[�`��
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

            // �ŏI�I�ȐF��ݒ�
            GetComponent<SpriteRenderer>().color = targetColors[i];
        }
    }
}