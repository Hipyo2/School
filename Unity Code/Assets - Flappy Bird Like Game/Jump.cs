using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Jump : MonoBehaviour
{
    public Rigidbody2D rb2d;
    public float flapStrength = 6;
    public LogicScript logic;
    public bool birdAlive;
    //public CircleCollider cc;
    // Start is called before the first frame update

    void Start()
    {
        logic = GameObject.FindGameObjectWithTag("Logic").GetComponent<LogicScript>();
        birdAlive = true;
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.Space) == true && birdAlive)
        {
            rb2d.velocity = Vector2.up * flapStrength;
        }
        if(transform.position.y < -10 && birdAlive)
        {
            logic.gameOver();
            flapStrength = 0;
            birdAlive = false;
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        logic.gameOver();
        flapStrength = 0;
        birdAlive = false;
    }
}
