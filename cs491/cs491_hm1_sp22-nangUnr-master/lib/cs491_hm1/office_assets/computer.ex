defmodule Cs491Hm1.OfficeAssets.Computer do
  use Ecto.Schema
  import Ecto.Changeset

  schema "computer" do
    field :brand, :string
    field :operating_systems_version, :integer

    timestamps()
  end

  @doc false
  def changeset(computer, attrs) do
    computer
    |> cast(attrs, [:brand, :operating_systems_version])
    |> validate_required([:brand, :operating_systems_version])
  end
end
