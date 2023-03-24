defmodule InClass.Company.Generalarea do
  use Ecto.Schema
  import Ecto.Changeset
  alias InClass.Company.Task

  schema "generalareas" do
    field :name, :string
    has_many(:tasks, Task)
    timestamps()
  end

  @doc false
  def changeset(generalarea, attrs) do
    generalarea
    |> cast(attrs, [:name])
    |> validate_required([:name])
  end
end
