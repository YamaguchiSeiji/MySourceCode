using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Dreamteck.Forever;
using static Unity.Collections.Unicode;
using System.Threading;
using System;
using UnityEngine.Events;

public class ActorController : MonoBehaviour
{
    private Runner runner;
    private bool isSpeedUp;
    private float time;
    public float scale = 2.0f;

    const float LOAD_WIDTH = 6f;
    const float MOVE_MAX = 2.5f;
    Vector3 previousPos, currentPos;
    public AudioSource updraftAudio;
    public AudioSource powerUpAudio;


    [System.Serializable]
    public class PlayerPositionEvent : UnityEvent<float, float, float>
    {
    }

    public PlayerPositionEvent OnPlayerPositionChanged = new PlayerPositionEvent();

    void Start()
    {
        runner = GetComponent<Runner>();
        isSpeedUp = false;
    }

    void Update()
    {
        
        if (Input.GetMouseButtonDown(0))
        {
            previousPos.x = Input.mousePosition.x;
        }
        if (Input.GetMouseButton(0))
        {
            // スワイプによる移動距離を取得
            currentPos.x = Input.mousePosition.x;
            float diffDistance = (currentPos.x - previousPos.x) / Screen.width * LOAD_WIDTH;

            // 次のローカルx座標を設定 ※道の外にでないように
            float newX = Mathf.Clamp(transform.localPosition.x + diffDistance, -MOVE_MAX, MOVE_MAX);
            transform.localPosition = new Vector3(newX, transform.localPosition.y, -1);

            // タップ位置を更新
            previousPos = currentPos;
            runner.motion.offset.x = transform.localPosition.x;
        }
        

        if (isSpeedUp == true)
        {
            runner.followSpeed = 12.0f;
            if(Time.time - time > 3.0f)
            {
                isSpeedUp = false;
            }
        } else
        {
            runner.followSpeed = 12.0f;
        }
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.name == "Updraft")
        {
            isSpeedUp = true;
            time = Time.time;
            updraftAudio.Play();
        }
        if (collision.gameObject.tag == "Obstacle")
        {
            GameManager.GameOver();
            
        }
        if (collision.gameObject.name == "FireWorks")
        {
            TimeCounter timeCounter = GetComponent<TimeCounter>();
            GameController gameController = GetComponent<GameController>();
            scale += 0.5f;
            gameObject.transform.localScale = new Vector3(scale, scale, 5.0f);
            Destroy(collision.gameObject);
            GameController.timer += 10.0f;
            powerUpAudio.Play();
        }
    }
}