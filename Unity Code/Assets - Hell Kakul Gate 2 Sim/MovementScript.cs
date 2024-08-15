using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MovementScript : MonoBehaviour
{
    float moveSpeed = 2.3f;
    int buttonSetting = 1;
    private Vector3 lastClicked;
    float swiftness = StaticData.moveSpeed;

    float directionFlag;
    bool moving = false;
    // Start is called before the first frame update
    void Start()
    {
        directionFlag = StaticData.directionFlag;
        Debug.Log(directionFlag);
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetMouseButton(buttonSetting))
        {
            lastClicked = Camera.main.ScreenToWorldPoint(Input.mousePosition);
            lastClicked = lastClicked * directionFlag;
            moving = true;
        }
        if(moving && transform.position != lastClicked)
        {
            
            transform.position = Vector2.MoveTowards(transform.position, lastClicked, moveSpeed*Time.deltaTime*swiftness);
        }
        else
        {
            moving = false;
        }
    }
}
