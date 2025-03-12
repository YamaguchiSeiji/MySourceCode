using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

public class CollisionDisabler : MonoBehaviour
{
    [SerializeField] GameObject _apple; //Appleオブジェクトをアタッチ
    [SerializeField] GameObject _orange; //Orangeオブジェクトをアタッ

    void Start()
    {
       SetActiveCollision(false, _apple, _orange);
    }

    //衝突するかどうか、対象オブジェクト1、対象オブジェクト2を指定
    public static void SetActiveCollision(bool isCollide, GameObject targetObj1, GameObject targetObj2)
        {
          var colliders1 = targetObj1.GetComponentsInChildren<Collider>();
          var colliders2 = targetObj2.GetComponentsInChildren<Collider>();

          foreach (var col1 in colliders1)
          {
              foreach (var col2 in colliders2)
              {
                  Physics.IgnoreCollision(col1, col2, !isCollide);
               }
           }
        }
}