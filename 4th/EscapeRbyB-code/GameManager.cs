using UnityEngine;
public class GameManager
{
   private static GameManager _instance;
   public static GameManager Instance
   {
       get
       {
           if (_instance == null)
           {
               _instance = new GameManager();
           }
           return _instance;
       }
   }
    public bool IsSetGetRedObj {get; private set;}
    public void SetGetRedObj(bool value){
        IsSetGetRedObj = value;
    }
}