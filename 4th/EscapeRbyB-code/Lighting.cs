using System;
using System.Collections;
using System.Collections.Generic;
using Microsoft.Unity.VisualStudio.Editor;
using UnityEngine;
using UnityEngine.Rendering.Universal;

public class Lighting : MonoBehaviour
{
    [SerializeField] private GameObject LightingPanel;
    private double _time = 0;
    private double _time2 = 0;
    private int LightingCount = 0;
    private float randomTime;
    private int randomCount;
    private bool isPanel = false;

    private void Start(){
        randomTime = UnityEngine.Random.Range(5f, 15f);    
    }

    private void Update()
    {
        if(Time.time - _time2 > randomTime){
            if(Time.time - _time > 0.07f){
                _time = Time.time;
                if(isPanel == true){
                    isPanel = false;
                } else {
                    isPanel = true;
                }
                LightingPanel.SetActive(isPanel);
                LightingCount++;
                if(LightingCount >= 4){
                    _time2 = Time.time;
                    LightingCount = 0;
                    randomTime = UnityEngine.Random.Range(5f, 15f);
                }
            }
        }
    }
}
