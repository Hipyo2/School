using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
using TMPro;

public class StartLogic : MonoBehaviour
{
    float directionFlag = StaticData.directionFlag;

    // Start is called before the first frame update
    public void startGame()
    {
        SceneManager.LoadScene("SampleScene", LoadSceneMode.Single);
        StartCoroutine(waitScene(SceneManager.GetSceneByName("SampleScene")));


        //SceneManager.UnloadSceneAsync("Start Scene");
    }

    public IEnumerator waitScene(Scene scene)
    {
        while(!scene.isLoaded)
        {
            yield return null;
        }
        SceneManager.SetActiveScene(scene);
    }

    public void changeDir()
    {
        directionFlag *= -1;
        StaticData.directionFlag = directionFlag;
    }
}
