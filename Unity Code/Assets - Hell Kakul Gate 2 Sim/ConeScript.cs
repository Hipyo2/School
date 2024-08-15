using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class ConeScript : MonoBehaviour
{
    public LogicScript logic;
    public Queue<string> queue;
    public GameObject cone;
    int spins = 3;
    float timer = 0;
    float r = 0;
    float dirFlag;
    // Start is called before the first frame update
    void Start()
    {
        logic = GameObject.FindGameObjectWithTag("Logic").GetComponent<LogicScript>();
    }

    // Update is called once per frame
    void Update()
    {
        /**/
        //Debug.Log(spins);
        if(spins > 0)
        {
            if(queue.Peek() == "L")
            {
                dirFlag = 1;
            }
            else
            {
                dirFlag = -1;
            }
            if(timer > 0.5)
            {
                cone.SetActive(false);
            }
            if(timer > 1 && r < 4)
            {
                cone.SetActive(true);
                this.transform.Rotate(Vector3.forward,90f*dirFlag);
                timer = 0;
                logic.die++;
                r++;

                if(logic.die != logic.survive)
                {
                    cone.SetActive(false);
                    logic.endGame();
                }
            }
            if(r >= 4)
            {
                r = 0;
                spins--;
                queue.Dequeue();
            }
            
            
        }
        else
        {
            if(timer > 0.5)
            {
                cone.SetActive(false);
                logic.endGame();
                //SceneManager.UnloadSceneAsync("SampleScene");
            }
        }
        timer += Time.deltaTime;
    }

    public IEnumerator waitScene(Scene scene)
    {
        while(!scene.isLoaded)
        {
            yield return null;
        }
        SceneManager.SetActiveScene(scene);
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        logic.survive++;
    }
}
