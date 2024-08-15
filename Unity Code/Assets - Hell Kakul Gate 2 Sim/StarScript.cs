using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class StarScript : MonoBehaviour
{
    public Queue<string> queue;
    public GameObject cone;
    public GameObject stars;
    int spins;
    float rotate = 0;
    float timer = 0;
    public float dirFlag = 0;
    // Start is called before the first frame update
    void Start()
    {
        cone.SetActive(false);
        spins = 3;
        Rotate();
    }

    // Update is called once per frame
    void Update()
    {
        
        if(spins > 0)
        {
            //Debug.Log(spins);
            //Debug.Log(rotate);
            if(queue.Peek() == "L")
            {
                dirFlag = 1;
                if(rotate < 180)
                {
                    //Debug.Log(this.transform.eulerAngles.z < 180*dirFlag);
                    this.transform.Rotate(Vector3.forward,dirFlag*90f*Time.deltaTime);
                    rotate = rotate +(dirFlag*90f*Time.deltaTime);
                }
                if(rotate > 180)
                {
                    this.transform.eulerAngles = new Vector3(this.transform.eulerAngles.x, this.transform.eulerAngles.y, 0);
                    queue.Enqueue(queue.Peek());
                    queue.Dequeue();
                    rotate = 0;
                    spins--;
                }
            }
            else
            {
                dirFlag = -1;
                if(rotate > dirFlag*180)
                {
                    //Debug.Log(this.transform.eulerAngles.z < 180*dirFlag);
                    this.transform.Rotate(Vector3.forward,dirFlag*90f*Time.deltaTime);
                    rotate = rotate +(dirFlag*90f*Time.deltaTime);
                }
                if(rotate < dirFlag*180)
                {
                    this.transform.eulerAngles = new Vector3(this.transform.eulerAngles.x, this.transform.eulerAngles.y, 360);
                    queue.Enqueue(queue.Peek());
                    queue.Dequeue();
                    rotate = 0;
                    spins--;
                }
            }

        }
        else
        {
            if(timer > 1)
            {
                cone.SetActive(true);
                stars.SetActive(false);
            }
            timer = timer + Time.deltaTime;
        }
    }

    void Rotate()
    {
    
    }
}
