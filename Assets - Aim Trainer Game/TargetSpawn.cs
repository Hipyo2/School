using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TargetSpawn : MonoBehaviour
{
    public GameObject target;
    public Logic logic;
    float hOff = 5;
    float timer = 2;
    float gameTime = 0;
    float gameLength = 30;
    // Start is called before the first frame update
    void Start()
    {
        logic = GameObject.FindGameObjectWithTag("Logic").GetComponent<Logic>();
    }

    // Update is called once per frame
    void Update()
    {
        if(timer > 2 && gameTime < gameLength)
        {
            spawn();
            timer = 0;
        }
        if(gameLength < gameTime)
        {
            logic.GameOver();
        }

        gameTime = gameTime + Time.deltaTime;
        timer = timer + Time.deltaTime;
    }

    void spawn()
    {
        float lowest = transform.position.y - hOff;
        float highest = transform.position.y + hOff;

        Instantiate(target, new Vector3(Random.Range(transform.position.x - hOff,transform.position.x + hOff), Random.Range(lowest,highest), 0), transform.rotation);
    }
}
