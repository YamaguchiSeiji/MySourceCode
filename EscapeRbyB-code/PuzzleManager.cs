using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PuzzleManager : MonoBehaviour
{
    [SerializeField] private GameObject[] piece;
    [SerializeField] private GameObject puzzlePanel;
    public static bool[] isTruePiece;
    public static bool isPazzleCorrectAnswer = false;

    void Start(){
        isTruePiece = new bool[8];
    }

    void Update()
    {
        for(int i = 0; i < 8; i++){
            if(isTruePiece[i] == true){
                isPazzleCorrectAnswer = true;
            } else {
                isPazzleCorrectAnswer = false;
                break;
            }
        }
        
        if(isPazzleCorrectAnswer == true){
            Debug.Log("パズルクリア");
        }

    }

    public void PuzzleExit(){
        puzzlePanel.SetActive(false);
        Player.isInput = true;
    }
}
