using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MovementScript : MonoBehaviour
{
    public Rigidbody2D rb2d;
    public float currentSpeed = 0;
    public float accel = 0.01f;
    public float deccel = 6000;
    public int lastPress = 0;

    Vector2 prev;
    // Start is called before the first frame update
    void Start()
    {

    }

    void incSpeed()
    {
        currentSpeed = currentSpeed + (accel* Time.deltaTime);
        currentSpeed = Mathf.Clamp(currentSpeed, 0,5);
    }
    void decSpeed()
    {
        currentSpeed = currentSpeed - (deccel* Time.deltaTime);
        currentSpeed = Mathf.Clamp(currentSpeed, 0,5);
    }

    // Update is called once per frame
    void Update()
    {
        Vector2 move = new Vector2(Input.GetAxis("Horizontal"), Input.GetAxis("Vertical"));
        if(!Input.anyKey)
        {
            decSpeed();
            rb2d.velocity = move * currentSpeed;
        }
        else
        {
            incSpeed();
            rb2d.velocity = move * currentSpeed;
        }

    }
}
