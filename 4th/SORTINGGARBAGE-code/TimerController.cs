using System.Collections;
using TMPro;
using UnityEngine;

public class TimerController : MonoBehaviour
{
    public TMP_Text timerText;
    private int countdownTime = 3;
    private int gameTime = 0; // �Q�[�����Ԃ̏����l (�b)
    private bool isGameRunning = false;

    void Start()
    {
        StartCoroutine(StartCountdown());
    }

    IEnumerator StartCountdown()
    {
        Time.timeScale = 0; // �Q�[�����~

        while (countdownTime > 0)
        {
            timerText.text = countdownTime.ToString();
            yield return new WaitForSecondsRealtime(1f); // ���A���^�C���ł̑ҋ@
            countdownTime--;
        }

        timerText.text = "�X�^�[�g";
        yield return new WaitForSecondsRealtime(1f); // "�Q�[���X�^�[�g!!" ��1�b�ԕ\��

        Time.timeScale = 1; // �Q�[�����ĊJ
        StartCoroutine(StartGameTimer());
    }

    IEnumerator StartGameTimer()
    {
        isGameRunning = true;

        while (true) // �Q�[�����Ԃ������Ȃ��ő������郋�[�v
        {
            yield return new WaitForSeconds(1f);
            gameTime++;

            UpdateTimerDisplay();

            // �����ɕK�v�ȃQ�[���̏�����ǉ��ł��܂�
        }
    }

    void UpdateTimerDisplay()
    {
        timerText.text = gameTime.ToString();
    }

    void EndGame()
    {
        isGameRunning = false;
        // �Q�[���I�����̏����������ɒǉ�
    }
}
