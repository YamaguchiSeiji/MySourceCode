using Dreamteck.Forever;
using System.Collections;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class GameController : MonoBehaviour
{
    public enum PlayState
    {
        None,
        Ready,
        Play,
        Finish,
    }

    public PlayState CurrentState = PlayState.None;

    [SerializeField] int countStartTime = 3;
    [SerializeField] TextMeshProUGUI countdownText = null;
    [SerializeField] TextMeshProUGUI timerText = null;
    [SerializeField] GameObject target;
    float currentCountDown = 0;
    public static float timer = 20;
    Runner runner;
    public AudioSource countDownAudio;
    public AudioSource BGM;
    private float _time;

    private SpriteRenderer SpriteRenderer { get; set; }
    [SerializeField] private Renderer _target;

    void Start()
    {
        CountDownStart();
        runner = target.GetComponent<Runner>();
        runner.follow = false;
        SpriteRenderer = target.GetComponent<SpriteRenderer>();
        timer = 20;
    }

    void Update()
    {
        timerText.text = "Time Limit : 20.0 s";

        if (CurrentState == PlayState.Ready)
        {
            currentCountDown -= Time.deltaTime;

            int intNum = 0;

            if (currentCountDown <= (float)countStartTime && currentCountDown > 0)
            {
                intNum = (int)Mathf.Ceil(currentCountDown);
                countdownText.text = intNum.ToString();

                if (intNum == 3 && !countDownAudio.isPlaying)
                {
                    countDownAudio.Play();
                }
            }
            else if (currentCountDown <= 0)
            {
                StartPlay();
                countdownText.text = "Start!!";
                BGM.Play();
                StartCoroutine(WaitErase());
            }
        }
        else if (CurrentState == PlayState.Play)
        {
            runner.follow = true;
            timer -= Time.deltaTime;
            timerText.text = "Time Limit : " + timer.ToString("00.0") + " s";
            CountDown();
        }
        else
        {
            timer = 20;
            timerText.text = "Time Limit : 20.0 s";
        }
    }

    void CountDownStart()
    {
        currentCountDown = (float)countStartTime;
        SetPlayState(PlayState.Ready);
        countdownText.gameObject.SetActive(true);
    }

    void StartPlay()
    {
        Debug.Log("Start!!!");
        SetPlayState(PlayState.Play);
        runner.follow = true;
    }

    IEnumerator WaitErase()
    {
        yield return new WaitForSeconds(2f);
        countdownText.gameObject.SetActive(false);
    }

    void SetPlayState(PlayState state)
    {
        CurrentState = state;
    }

    void CountDown()
    {
        if (timer <= 0)
        {
            GameManager.GameOver();
        }
        else if (timer <= 2)
        {
            LightBlinking(0.1f);
        }
        else if (timer <= 5)
        {
            LightBlinking(0.5f);
        }
        else if (timer <= 10)
        {
            LightBlinking(1.0f);
        }
        else
        {
            SpriteRenderer.color = new Color(255f, 255f, 255f);
        }
    }

    private void LightBlinking(float interval)
    {
        _time += Time.deltaTime;
        var repeatValue = Mathf.Repeat((float)_time, interval);

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
