using UnityEngine;

public class BackGroundMove : MonoBehaviour
{
    [SerializeField] float speed;
    float reduction = 0.0078125f;

    void Update()
    {
        Vector3 pos = transform.position;
        pos.y += speed * reduction / 16f;
        transform.position = pos;
    }
}