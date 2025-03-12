using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

public class MoveBird : MonoBehaviour
{
    [SerializeField] private GameObject start;
    [SerializeField] private GameObject end;
    [SerializeField] private float MoveSpeed;
    private Vector2 pos;
    private Vector2 spos, epos;
    public int num = -1;

    // Update is called once per frame
    void Update()
    {
        pos = transform.position;
        spos = start.transform.position;
        epos = end.transform.position;
        transform.Translate(transform.right * MoveSpeed * Time.deltaTime * num);
        if(pos.x < spos.x - 2.3f)
        {
            num = 1;
            transform.rotation = Quaternion.Euler(0f, 180f, 0f);

        } else if(pos.x > spos.x + 2.3f)
        {
            num = -1;
            transform.rotation = Quaternion.Euler(0f, 0f, 0f);
        }
    }
}
