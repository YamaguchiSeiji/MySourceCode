using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Sky : MonoBehaviour
{
    public GameObject sky;
    bool yol_yapildi = false;

    void OnTriggerEnter2D(Collider2D temas)
    {
        if(temas.gameObject.tag == "player" && yol_yapildi == false)
        {
            Vector3 spawn_location = new Vector3(transform.position.x, transform.position.y + 10, 0);
            Instantiate(sky, spawn_location, Quaternion.identity);
            yol_yapildi = true;
        }
    }
}
