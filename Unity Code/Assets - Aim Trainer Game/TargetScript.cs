using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class TargetScript : MonoBehaviour
{
    public Logic logic;
    float timer = 0;
    float targetLife = 2;
    // Start is called before the first frame update
    void Start()
    {
        logic = GameObject.FindGameObjectWithTag("Logic").GetComponent<Logic>();
    }

    // Update is called once per frame
    void Update()
    {
        if(timer > targetLife)
        {
            Destroy(gameObject);
        }
        timer = timer + Time.deltaTime;
    }

    void OnMouseDown()
    {
        Debug.Log("Clicked!");
        logic.increaseScore(1);
        Destroy(gameObject);
    }
}
