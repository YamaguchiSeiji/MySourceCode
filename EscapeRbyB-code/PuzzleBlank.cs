using System.Collections;
using System.Collections.Generic;
using JetBrains.Annotations;
using Unity.VisualScripting;
using UnityEngine;

public class PuzzleBlank : MonoBehaviour
{   
    public static Vector2 blankPosition;
    public static Vector2 piecePosition;
    // Start is called before the first frame update
    void Start()
    {
        blankPosition = transform.position;
    }

    // Update is called once per frame
    void Update()
    {
        blankPosition = transform.position;
    }

    private void OnTriggerStay2D(Collider2D target){
        if(target.gameObject.CompareTag("Piece") && PuzzlePiece.isPieceMove == true){
            Vector2 tmp = new (0, 0);
            tmp = transform.position;
            transform.position = PuzzlePiece.prevPos;
            PuzzlePiece.prevPos = tmp;
        }
    }

}
