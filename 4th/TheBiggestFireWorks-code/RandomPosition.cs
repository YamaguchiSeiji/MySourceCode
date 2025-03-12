using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

public class RandomPosition : MonoBehaviour
{
    [SerializeField] private GameObject start;
    [SerializeField] private GameObject end;
    [SerializeField] private float MoveSpeed;
    private Vector2 pos;
    private Vector2 spos, epos;
    public int num = -1;
    // Start is called before the first frame update
    void Start()
    {
        pos = transform.position;
        spos = start.transform.position;
        epos = end.transform.position;
        pos.x = Random.Range(spos.x - 2.5f, spos.x + 2.5f);
        pos.y = Random.Range(spos.y, epos.y);
        transform.position = pos;
    }
}
