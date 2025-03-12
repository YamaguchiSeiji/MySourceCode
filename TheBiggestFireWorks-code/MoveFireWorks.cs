using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using UnityEditor.Rendering;

public class MoveFireWorks : MonoBehaviour
{
    [SerializeField] private float MoveSpeed;
    private Vector2 pos;

    // Update is called once per frame
    void Update()
    {   
            pos = transform.position;
            pos.y += MoveSpeed * Time.deltaTime;
            transform.position = pos;
    }
}
