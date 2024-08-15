using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class KukuScript : MonoBehaviour
{
    public GameObject stars;
    public GameObject cone;
    public Queue<string> q= new Queue<string>();
    private List<string> v = new List<string>();
    private StarScript starscript;
    private ConeScript conescript;
    // Start is called before the first frame update
    void Start()
    {
        cone.SetActive(false);
        v.Add("L"); v.Add("R");
        int i = 0;
        while(i < 3)
        {
            q.Enqueue(v[Random.Range(0,2)]);
            i++;
        }
        starscript = stars.GetComponent<StarScript>();
        conescript = cone.GetComponent<ConeScript>();
        conescript.queue = q;
        starscript.queue = q;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
