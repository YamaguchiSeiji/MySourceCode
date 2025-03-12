using System;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class Password : MonoBehaviour
{
    [SerializeField]
    public TextMeshProUGUI text;

    [SerializeField]
    GameObject panel;
    string correct="0130";

    public static bool isCorrect = false;

    public void OnclickNum(int Num){
        text.text+=Num.ToString();
    }

    public void OnclickEnter(){
        if(correct==text.text){
            text.text="OK!";
            isCorrect = true;
        }
        else{
            text.text="NO!";
            isCorrect = false;
        }
    }

    public void OnclickDelete(){
        text.text=null;
    }

    public void OnclickClose(){
        panel.SetActive(false);
        Player.isInput = true;
    }

}
