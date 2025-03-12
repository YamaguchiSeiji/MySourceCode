using UnityEngine;
using TMPro;
using DG.Tweening;

public class ScoreManager : MonoBehaviour
{
    // �V���O���g���C���X�^���X
    public static ScoreManager Instance { get; private set; }

    // �X�R�A��\������TextMeshPro�̎Q��
    public TextMeshProUGUI scoreText;
    // MISS���b�Z�[�W��\������TextMeshPro�̎Q��
    public TextMeshProUGUI missText;
    // �R���{��\������TextMeshPro�̎Q��
    public TextMeshProUGUI comboText;

    // ���݂̃X�R�A (public �ŃA�N�Z�X�\�ɂ���)
    public int score = 0;
    // �~�X��
    private int missCount = 0;
    // �ő�~�X��
    private const int maxMissCount = 3;

    // �R���{�֘A
    private int comboCount = 0; // �R���{�J�E���g
    private float comboMultiplier = 1.0f; // �R���{�{��

    private const int initialScoreAmount = 100; // �������Z�X�R�A

    void Awake()
    {
        // �V���O���g���C���X�^���X�̐ݒ�
        if (Instance == null)
        {
            Instance = this;
            DontDestroyOnLoad(gameObject); // �V�[���ԂŃI�u�W�F�N�g��j�����Ȃ�
        }
        else
        {
            Destroy(gameObject); // ���łɃC���X�^���X������ꍇ�́A���̃I�u�W�F�N�g��j��
        }
    }

    void Start()
    {
        UpdateScoreText();
        missText.gameObject.SetActive(false); // ������Ԃł͔�\��
        comboText.gameObject.SetActive(false); // ������Ԃł͔�\��
    }

    // �X�R�A�����Z����֐�
    public void AddScore()
    {
        comboCount++;
        comboMultiplier = 1.0f + 0.5f * comboCount; // �R���{�{�����X�V
        int finalScoreAmount = Mathf.RoundToInt(initialScoreAmount * comboMultiplier);
        score += finalScoreAmount;
        ObjectSpawner.Instance.IncreaseSpeedWithScore(); // �X�R�A�����������ۂ̑��x�X�V
        UpdateScoreText();
        ShowComboMessage();
    }

    // �X�R�A�����Z����֐�
    public void SubScore()
    {
        score -= initialScoreAmount;
        comboCount = 0; // �R���{�����Z�b�g
        comboMultiplier = 1.0f; // �R���{�{�������Z�b�g

        missCount++; // �~�X�J�E���g�𑝂₷
        if (missCount >= maxMissCount)
        {
            EndGame(); // �ő�~�X�񐔂ɒB������Q�[���I��
        }
        else
        {
            ShowMissMessage();
        }

        UpdateScoreText();
        HideComboMessage();
    }

    // �X�R�A��TextMeshPro�ɕ\������֐�
    void UpdateScoreText()
    {
        scoreText.text = "�X�R�A: " + score.ToString();
        if (score < 0)
        {
            scoreText.color = Color.red;
        }
        else
        {
            scoreText.color = Color.black;
        }
    }

    // MISS���b�Z�[�W���ӂ���ƕ\������֐�
    void ShowMissMessage()
    {
        missText.gameObject.SetActive(true);
        missText.text = "�~�X";
        missText.color = Color.red;

        // �t�F�[�h�C���A�j���[�V����
        missText.transform.localScale = Vector3.zero;
        missText.transform.DOScale(1f, 0.2f).SetEase(Ease.OutBack);
        missText.DOFade(1f, 0.2f).SetEase(Ease.OutQuad);

        // 2�b��ɔ�\���ɂ���
        Invoke("HideMissMessage", 1f);
    }

    void HideMissMessage()
    {
        // �t�F�[�h�A�E�g�A�j���[�V����
        missText.DOFade(0f, 0.2f).SetEase(Ease.InQuad).OnComplete(() =>
        {
            missText.gameObject.SetActive(false);
        });
    }

    // �R���{���b�Z�[�W��\������֐�
    void ShowComboMessage()
    {
        comboText.gameObject.SetActive(true);
        comboText.text = "�R���{ x" + comboCount.ToString();
        comboText.color = Color.green;

        // �t�F�[�h�C���A�j���[�V����
        comboText.transform.localScale = Vector3.zero;
        comboText.transform.DOScale(1f, 0.2f).SetEase(Ease.OutBack);
        comboText.DOFade(1f, 0.2f).SetEase(Ease.OutQuad);
    }

    void HideComboMessage()
    {
        // �t�F�[�h�A�E�g�A�j���[�V����
        comboText.DOFade(0f, 0.2f).SetEase(Ease.InQuad).OnComplete(() =>
        {
            comboText.gameObject.SetActive(false);
        });
    }

    // �Q�[���I������
    void EndGame()
    {
        Debug.Log("Game Over - Too many misses!");
        // �Q�[���I�������������ɒǉ�����i�Ⴆ�΃V�[���̃����[�h�A�I�������Ȃǁj
        // ���̗�ł̓G�f�B�^�ł̎��s���ɂ͒�~����
#if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;
#else
        Application.Quit(); // �r���h�����A�v���P�[�V�����ł͏I������
#endif
    }
}
