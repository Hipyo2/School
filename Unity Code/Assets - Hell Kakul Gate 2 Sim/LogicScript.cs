using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
public class LogicScript : MonoBehaviour
{
    public int die = 0;
    public int survive = 0;

    public void endGame()
    {
        SceneManager.LoadScene("GameOverScene", LoadSceneMode.Single);
        StartCoroutine(waitScene(SceneManager.GetSceneByName("GameOverScene")));
    }

    public void restartGame()
    {
        SceneManager.LoadScene("Start Scene", LoadSceneMode.Single);
        StartCoroutine(waitScene(SceneManager.GetSceneByName("Start Scene")));
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
