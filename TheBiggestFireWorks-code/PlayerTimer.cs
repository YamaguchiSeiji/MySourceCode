using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class TimeCounter : MonoBehaviour
{
    private SpriteRenderer SpriteRenderer { get; set; }
    [SerializeField] private Renderer _target;

    //�J�E���g�_�E��
    public float countdown;
    private float _time;
    //���Ԃ�\������Text�^�̕ϐ�
    private Text timeText;

    // Update is called once per frame
    void Start()
    {
        SpriteRenderer = GetComponent<SpriteRenderer>();
        countdown = GameController.timer;
    }

    void CountDown()
    {
        //���Ԃ��J�E���g�_�E������
        countdown -= Time.deltaTime;

        //countdown��0�ȉ��ɂȂ����Ƃ�
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
        // �����������o�߂�����
        _time += Time.deltaTime;

        // ����cycle�ŌJ��Ԃ��l�̎擾
        // 0�`cycle�͈̔͂̒l��������
        var repeatValue = Mathf.Repeat((float)_time, interval);

        // ��������time�ɂ����閾�ŏ�Ԃ𔽉f
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