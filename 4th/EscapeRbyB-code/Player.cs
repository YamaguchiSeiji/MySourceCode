using System.Collections;
using System.Collections.Generic;
using System.Net.NetworkInformation;
using TMPro;
using Unity.VisualScripting;
using UnityEditor;
using UnityEngine;
using UnityEngine.SocialPlatforms;

public class Player : MonoBehaviour
{
    [SerializeField] private float moveSpeed = 5f;
    [SerializeField] private GameObject PlayerTextPanel;
    [SerializeField] private TextMeshProUGUI PlayerText;
    [SerializeField] private Animator animator;
    [SerializeField] private GameObject CodePanelUI;
    [SerializeField] GameObject PlayerRedOrb, PlayerBlueOrb, PlayerPinkOrb, PlayerWhiteOrb;
    [SerializeField] private GameObject PuzzlePanel;
    [SerializeField] private GameObject GameClearPanel;
    [SerializeField] private GameObject Rock;
    [SerializeField] private GameObject star;
    [SerializeField] private GameObject hintPaper;
    [SerializeField] private GameObject Blob;

    private bool isHoraizontalMove = false;
    private bool isVerticalMove = false;
    private bool isInteract = false;
    private bool isTextPanel = false;
    private bool isOrangeOrb, isBlueOrb, isPinkOrb, isWhiteOrb= false;
    private bool isCorrectOrange, isCorrectBlue, isCorrectPink, isCorrectWhite = false;
    private bool isHaveOrb = false;
    private bool isFocasSide, isFocasFront, isFocasBack;
    public static bool isInput = true;
    private bool isPazzleE = true;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //プレイヤー移動処理
        if(isInput == true){
            if(Input.GetKey(KeyCode.D) && isVerticalMove == false){
                this.transform.position += new Vector3(moveSpeed*0.01f, 0, 0);
                isHoraizontalMove = true;
                this.transform.rotation = Quaternion.Euler(0, 180, 0);
                animator.SetBool("isMoveSide", true);
                animator.SetBool("isMoveFront", false);
                animator.SetBool("isMoveBack", false);
                isFocasSide = true;
                isFocasBack = false;
                isFocasFront = false;
            } else if(Input.GetKey(KeyCode.A) && isVerticalMove == false){
                this.transform.position -= new Vector3(moveSpeed*0.01f, 0, 0);
                isHoraizontalMove = true;
                this.transform.rotation = Quaternion.Euler(0, 0, 0);
                animator.SetBool("isMoveSide", true);
                animator.SetBool("isMoveFront", false);
                animator.SetBool("isMoveBack", false);
                isFocasSide = true;
                isFocasBack = false;
                isFocasFront = false;
            } else {
                isHoraizontalMove = false;
            }

            if(Input.GetKey(KeyCode.W) && isHoraizontalMove == false){
                this.transform.position += new Vector3(0, moveSpeed*0.01f, 0);
                isVerticalMove = true;
                animator.SetBool("isMoveBack", true);
                animator.SetBool("isMoveFront", false);
                animator.SetBool("isMoveSide", false);
                isFocasBack = true;
                isFocasSide = false;
                isFocasFront = false;
            } else if(Input.GetKey(KeyCode.S) && isHoraizontalMove == false){
                this.transform.position -= new Vector3(0, moveSpeed*0.01f, 0);
                isVerticalMove = true;
                animator.SetBool("isMoveFront", true);
                animator.SetBool("isMoveSide", false);
                animator.SetBool("isMoveBack", false);
                isFocasFront = true;
                isFocasBack = false;
                isFocasSide = false;
            } else {
                isVerticalMove = false;
            }
        }
        
        if(isHoraizontalMove == false && isVerticalMove == false){
            if(isFocasSide == true){
                animator.SetBool("isIdleSide", true);
                animator.SetBool("isMoveFront", false);
                animator.SetBool("isMoveBack", false);
                animator.SetBool("isIdleFront", false);
                animator.SetBool("isIdleBack", false);
                animator.SetBool("isMoveSide", false);
                isFocasBack = false;
                isFocasFront = false;
            } else if(isFocasBack == true){
                animator.SetBool("isIdleBack", true);
                animator.SetBool("isMoveFront", false);
                animator.SetBool("isMoveBack", false);
                animator.SetBool("isIdleFront", false);
                animator.SetBool("isMoveBack", false);
                animator.SetBool("isIdleSide", false);
                isFocasSide = false;
                isFocasFront = false;
            } else if(isFocasFront == true){
                animator.SetBool("isIdleFront", true);
                animator.SetBool("isMoveFront", false);
                animator.SetBool("isMoveBack", false);
                animator.SetBool("isMoveFront", false);
                animator.SetBool("isIdleBack", false);
                animator.SetBool("isIdleSide", false);
                isFocasSide = false;
                isFocasBack = false;
            }
        } else {
            animator.SetBool("isIdleFront", false);
            animator.SetBool("isIdleBack", false);
            animator.SetBool("isIdleSide", false);
        }

        //インタラクト処理
        if(Input.GetKey(KeyCode.E)){
            isInteract = true;
        } else {
            isInteract = false;
        }

        //UI処理
        if(isTextPanel == true){
            PlayerTextPanel.SetActive(true);
            isInput = false;
        }
        if(Input.GetMouseButton(0) && isTextPanel == true){
            isTextPanel = false;
            PlayerTextPanel.SetActive(false);
            isInput = true;
        }
        if(Password.isCorrect == true){
            PlayerText.text = "トゲが破壊された。\nこの先に進めばおそらく脱出できるだろう。";
            isTextPanel = true;
            Password.isCorrect = false;
            CodePanelUI.SetActive(false);
            isInput = true;
            Rock.SetActive(false);
        }
        if(PuzzleManager.isPazzleCorrectAnswer == true){
            PlayerText.text = "パズルが完成した。";
            star.SetActive(true);
            isTextPanel = true;
            PuzzlePanel.SetActive(false);
            PuzzleManager.isPazzleCorrectAnswer = false;
            isPazzleE = false;
        }
        if(isCorrectBlue && isCorrectOrange && isCorrectPink && isCorrectWhite){    
            isTextPanel = true;
            PlayerText.text = "何かが変わったはず。\n探索してみよう。";
            isInput = false;
            Blob.SetActive(false);
            isCorrectBlue = false;
        }
    }

    void OnTriggerStay2D(Collider2D target){

        //ゴール判定
        if (target.gameObject.name == "Goal")
        {
            GameClearPanel.SetActive(true);
            isInput = false;
            animator.SetBool("isIdleSide", false);
            animator.SetBool("isMoveFront", false);
            animator.SetBool("isMoveBack", false);
            animator.SetBool("isIdleFront", true);
            animator.SetBool("isIdleBack", false);
            animator.SetBool("isMoveSide", false);
        }

        //鍵入手
        if (target.gameObject.name == "Key" && isInteract == true){
            Destroy(target.gameObject);
            PlayerText.text = "鍵を手に入れた。";
            isTextPanel = true;
        }

        //暗証番号ギミック
        if(target.gameObject.name == "CodePanel" && isInteract == true){
            CodePanelUI.SetActive(true);
            isInput = false;
        }

        //オレンジ台座ギミック
        if(target.gameObject.name == "RedOrb" && isInteract == true){
            if(isHaveOrb == false){
                Destroy(target.gameObject);
                isOrangeOrb = true;
                PlayerText.text = "橙色のオーブを手に入れた。";
                isTextPanel = true;
                isHaveOrb = true;
            } else {
                PlayerText.text = "これ以上オーブを持つことはできない。\n今持っているオーブを台座に置きに行こう。";
                isTextPanel = true;
            }
        }
        if(target.gameObject.name == "RedStand" && isInteract == true){
            if(isOrangeOrb == true){
                PlayerRedOrb.SetActive(true);
                PlayerText.text = "正しい位置にオーブを置いた。";
                isTextPanel = true;
                isOrangeOrb = false;
                isCorrectOrange = true;
                isHaveOrb = false;
            } else if(isCorrectOrange == false){
                PlayerText.text = "対応するオーブを所持していない。";
                isTextPanel = true;
            }
        }

        //ブルー台座ギミック
        if(target.gameObject.name == "BlueOrb" && isInteract == true){
            if(isHaveOrb == false){
                Destroy(target.gameObject);
                isBlueOrb = true;
                PlayerText.text = "青色のオーブを手に入れた。";
                isTextPanel = true;
                isHaveOrb = true;
            } else {
                PlayerText.text = "これ以上オーブを持つことはできない。\n今持っているオーブを台座に置きに行こう。";
                isTextPanel = true;
            }
        }
        if(target.gameObject.name == "BlueStand" && isInteract == true){
            if(isBlueOrb == true){
                PlayerBlueOrb.SetActive(true);
                PlayerText.text = "正しい位置にオーブを置いた。";
                isTextPanel = true;
                isBlueOrb = false;
                isCorrectBlue = true;
                isHaveOrb = false;
            } else if(isCorrectBlue == false){
                PlayerText.text = "対応するオーブを所持していない。";
                isTextPanel = true;
            }
        }

        //ピンク台座ギミック
        if(target.gameObject.name == "PinkOrb" && isInteract == true){
            if(isHaveOrb == false){
                Destroy(target.gameObject);
                isPinkOrb = true;
                PlayerText.text = "桃色のオーブを手に入れた。";
                isTextPanel = true;
                isHaveOrb = true;
            } else {
                PlayerText.text = "これ以上オーブを持つことはできない。\n今持っているオーブを台座に置きに行こう。";
                isTextPanel = true;
            }
        }
        if(target.gameObject.name == "PinkStand" && isInteract == true){
            if(isPinkOrb == true){
                PlayerPinkOrb.SetActive(true);
                PlayerText.text = "正しい位置にオーブを置いた。";
                isTextPanel = true;
                isPinkOrb = false;
                isCorrectPink = true;
                isHaveOrb = false;
            } else if(isCorrectPink == false){
                PlayerText.text = "対応するオーブを所持していない。";
                isTextPanel = true;
            }
        }

        //ホワイト台座ギミック
        if(target.gameObject.name == "WhiteOrb" && isInteract == true){
            if(isHaveOrb == false){
                Destroy(target.gameObject);
                isWhiteOrb = true;
                PlayerText.text = "白色のオーブを手に入れた。";
                isTextPanel = true;
                isHaveOrb = true;
            } else {
                PlayerText.text = "これ以上オーブを持つことはできない。\n今持っているオーブを台座に置きに行こう。";
                isTextPanel = true;
            }
        }
        if(target.gameObject.name == "WhiteStand" && isInteract == true){
            if(isWhiteOrb == true){
                PlayerWhiteOrb.SetActive(true);
                PlayerText.text = "正しい位置にオーブを置いた。";
                isTextPanel = true;
                isWhiteOrb = false;
                isCorrectWhite = true;
                isHaveOrb = false;
            } else if(isCorrectWhite == false){
                PlayerText.text = "対応するオーブを所持していない。";
                isTextPanel = true;
            }
        }

        if(target.gameObject.name == "PuzzlePanel" && isInteract == true && isPazzleE == true){
            PuzzlePanel.SetActive(true);
            isInput = false;
        }

        if(target.gameObject.name == "PikaPika" && isInteract == true){
            hintPaper.SetActive(true);
            isInput = false;
        }
    }
}