using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HintPaper : MonoBehaviour
{
    [SerializeField] private GameObject hintPanel;

    public void PuzzleExit(){
        hintPanel.SetActive(false);
        Player.isInput = true;
    }
}
