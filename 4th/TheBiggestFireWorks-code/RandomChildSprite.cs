using UnityEngine;

public class RandomChildSprite : MonoBehaviour
{
    // �����_�����������qSprite�̔z��
    public SpriteRenderer[] childSprites;

    void Start()
    {
        // �qSprite��1�ȏ゠�邩���m�F
        if (childSprites.Length > 0)
        {
            // �����_���ȃC���f�b�N�X��I��
            int randomIndex = Random.Range(0, childSprites.Length);

            // �I�����ꂽ�qSprite��\�����A����ȊO�̎qSprite���\���ɂ���
            for (int i = 0; i < childSprites.Length; i++)
            {
                childSprites[i].gameObject.SetActive(i == randomIndex);
            }

            // �����_���ȍ��W�𐶐�
            float randomX = Random.Range(-0.5f, 0.5f);
            float randomY = Random.Range(-0.5f, 0.5f); // y���W��-0.5f����0.5f�͈̔͂Ń����_��

            // �X�P�[���̔䗦��ێ����A�����_���ȃX�P�[����ݒ�
            float randomScale = Random.Range(0.5f, 1f); // 0.5����1�͈̔͂Ń����_���ȃX�P�[���𐶐�

            // �����_���ȍ��W�Ɋe�qSprite���ړ�
            foreach (SpriteRenderer childSprite in childSprites)
            {
                // �X�P�[���̔䗦��ێ����A�����_���ȃX�P�[����ݒ�
                childSprite.transform.localScale = new Vector3(childSprite.transform.localScale.x * randomScale, childSprite.transform.localScale.y * randomScale, childSprite.transform.localScale.z);

                // ���W��ݒ�
                childSprite.transform.localPosition = new Vector3(randomX, randomY, childSprite.transform.localPosition.z);
            }
        }
    }
}
