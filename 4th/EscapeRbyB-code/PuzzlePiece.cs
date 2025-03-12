using System;
using System.Collections.Generic;
using Unity.Mathematics;
using UnityEditor.Compilation;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

// Imageコンポーネントを必要とする
[RequireComponent ( typeof ( Image ) )]


// ドラッグとドロップに関するインターフェースを実装する
public class PuzzlePiece : MonoBehaviour, IDragHandler, IBeginDragHandler, IEndDragHandler//, IDropHandler
{
    // ドラッグ前の位置
    public static Vector2 prevPos;
    public static bool isPieceMove = false;
    private string pieceName;

    void Start(){
        prevPos = transform.position;
        pieceName = gameObject.name;
    }

    void Update(){
        if(prevPos.x == PuzzleBlank.blankPosition.x && Mathf.Abs(PuzzleBlank.blankPosition.y - prevPos.y) < Mathf.Abs(80)){
            isPieceMove = true;
        } else if(prevPos.y == PuzzleBlank.blankPosition.y && Mathf.Abs(PuzzleBlank.blankPosition.x - prevPos.x) < Mathf.Abs(80)){
            isPieceMove = true;
        } else {
            isPieceMove = false;
        }
    }

    public void OnBeginDrag ( PointerEventData eventData )
    {
        prevPos = transform.position;
    }

    public void OnDrag ( PointerEventData eventData )
    {
        // ドラッグ中は位置を更新する
        transform.position = eventData.position;
    }

    public void OnEndDrag ( PointerEventData eventData )
    {
        // ドラッグ前の位置に戻す
        transform.position = prevPos;
    }

    private void OnTriggerEnter2D(Collider2D target){
        if(target.gameObject.name == "Collider1" && pieceName == "7"){
            PuzzleManager.isTruePiece[0] = true;
        }
        if(target.gameObject.name == "Collider2" && pieceName == "3"){
            PuzzleManager.isTruePiece[1] = true;
        }
        if(target.gameObject.name == "Collider3" && pieceName == "1"){
            PuzzleManager.isTruePiece[2] = true;
        }
        if(target.gameObject.name == "Collider4" && pieceName == "2"){
            PuzzleManager.isTruePiece[3] = true;
        }
        if(target.gameObject.name == "Collider5" && pieceName == "8"){
            PuzzleManager.isTruePiece[4] = true;
        }
        if(target.gameObject.name == "Collider6" && pieceName == "6"){
            PuzzleManager.isTruePiece[5] = true;
            Debug.Log(PuzzleManager.isTruePiece[5]);
        }
        if(target.gameObject.name == "Collider7" && pieceName == "5"){
            PuzzleManager.isTruePiece[6] = true;
        }
        if(target.gameObject.name == "Collider8" && pieceName == "4"){
            PuzzleManager.isTruePiece[7] = true;
        }
    }

    private void OnTriggerExit2D(Collider2D target){
        if(target.gameObject.name == "Collider1" && pieceName == "7"){
            PuzzleManager.isTruePiece[0] = false;
        }
        if(target.gameObject.name == "Collider2" && pieceName == "3"){
            PuzzleManager.isTruePiece[1] = false;
        }
        if(target.gameObject.name == "Collider3" && pieceName == "1"){
            PuzzleManager.isTruePiece[2] = false;
        }
        if(target.gameObject.name == "Collider4" && pieceName == "2"){
            PuzzleManager.isTruePiece[3] = false;
        }
        if(target.gameObject.name == "Collider5" && pieceName == "8"){
            PuzzleManager.isTruePiece[4] = false;
        }
        if(target.gameObject.name == "Collider6" && pieceName == "6"){
            PuzzleManager.isTruePiece[5] = false;
        }
        if(target.gameObject.name == "Collider7" && pieceName == "5"){
            PuzzleManager.isTruePiece[6] = false;
        }
        if(target.gameObject.name == "Collider8" && pieceName == "4"){
            PuzzleManager.isTruePiece[7] = false;
        }
    }

}