using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    public static float playerYPosition;
    public static float playerTime;
    public static float playerScale;

    public static void GameOver()
    {
        Debug.Log("GAMEOVER");
        ActorController movePlayer = FindObjectOfType<ActorController>();

        if (movePlayer != null)
        {
            Debug.Log("SUCCESS");
            playerYPosition = movePlayer.transform.position.y;
            playerTime = Time.time - 5;
            playerScale = movePlayer.scale;

            movePlayer.OnPlayerPositionChanged.Invoke(playerYPosition, playerTime, playerScale);
        }

        // ÉVÅ[ÉìÇêÿÇËë÷Ç¶ÇÈ
        SceneManager.LoadScene("End");
    }
}
