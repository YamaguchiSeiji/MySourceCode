using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Horror : MonoBehaviour
{
    [SerializeField] GameObject Fish;

    public float speed = 2f;		// 敵の移動速度
    public float moveRange = 5f;	// 移動範囲
    private Vector3 startPosition;	// 初期位置
    private bool TouchHorror = false;

    void Start(){
        startPosition = transform.position; // 初期位置を保存
    }

    void Update(){
        if(TouchHorror == true){
            transform.position += Vector3.down *  speed  * Time.deltaTime;
            Invoke(nameof(DestroyFish),0.7f);
        }
    }

    void DestroyFish(){
        Destroy(this.gameObject);
    }

    void OnTriggerEnter2D(Collider2D target){
        if(target.gameObject.name == "Player"){
            Debug.Log("yaaaaaaaaa,PoWERRRRRRR");
            gameObject.SetActive(true);
            TouchHorror = true ;
        }
    }
}
