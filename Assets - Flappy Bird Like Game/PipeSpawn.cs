using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PipeSpawn : MonoBehaviour
{
    public GameObject pipe;
    public float spawnRate = 2;
    public float timer = 0;
    public float hOff = 10;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if(timer < spawnRate)
        {
            timer = timer + Time.deltaTime;
        }
        else
        {
            timer = 0;
            spawn();
        }
        
    }

    void spawn()
    {
        float lowest = transform.position.y - hOff;
        float highest = transform.position.y + hOff;
        int z = 0;
        Instantiate(pipe, new Vector3(transform.position.x, Random.Range(lowest,highest), z), transform.rotation);
    }
}
