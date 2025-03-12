using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameStart : MonoBehaviour
{
    public void OnclickStart(){
        
        SceneManager.LoadScene("MainScene");

    }

    public void OnclickExit(){

        Application.Quit();
        UnityEditor.EditorApplication.isPlaying=false;
        
    }

}
