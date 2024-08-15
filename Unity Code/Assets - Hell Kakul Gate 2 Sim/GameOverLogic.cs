using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class GameOverLogic : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void menu()
    {
        SceneManager.LoadScene("Start Scene", LoadSceneMode.Single);
        StartCoroutine(waitScene(SceneManager.GetSceneByName("Start Scene")));
        //SceneManager.UnloadSceneAsync("GameOverScene");
    }

    public void play()
    {
        SceneManager.LoadScene("SampleScene", LoadSceneMode.Single);
        StartCoroutine(waitScene(SceneManager.GetSceneByName("SampleScene")));
        //SceneManager.UnloadSceneAsync("GameOverScene");
    }

    public IEnumerator waitScene(Scene scene)
    {
        while(!scene.isLoaded)
        {
            yield return null;
        }
        SceneManager.SetActiveScene(scene);
    }
}
